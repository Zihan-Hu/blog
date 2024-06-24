import { spawn } from 'node:child_process'
import path from 'node:path'
import { fileURLToPath } from 'node:url'
import process from 'node:process'
import { readFileSync } from 'node:fs'
import { readDirDeepSync } from 'read-dir-deep'
import consola from 'consola'
import parseGitIgnore from 'parse-gitignore'

const __filename = fileURLToPath(import.meta.url)
const __dirname = path.dirname(__filename)

const workspace = path.resolve(__dirname, '../..')

const includePatterns = ['**.cpp', '**.h', '**.hpp']

// 从 .clang-format-ignore 中读取忽略的文件 pattern
const clangFormatIgnorePath = path.resolve(workspace, '.clang-format-ignore')
const clangFormatIgnore = readFileSync(clangFormatIgnorePath)
const excludePatterns = parseGitIgnore(clangFormatIgnore).patterns

/**
 * @param {string[]} files
 * @returns {Promise<void>}
 */
function fixFiles(files) {
  return new Promise((resolve, reject) => {
    const child = spawn('clang-format', ['-i', ...files], {
      stdio: 'pipe',
      cwd: workspace,
    })

    child.stderr.pipe(process.stderr)
    child.addListener('close', (code) => {
      if (!code)
        resolve()
      else
        reject(new Error(`clang-format exited with code ${code}`))
    })
  })
}

try {
  const files = readDirDeepSync(workspace, {
    patterns: includePatterns,
    ignore: excludePatterns,
  })
  await fixFiles(files)
}
catch (error) {
  consola.error(error)
  process.exit(1)
}
