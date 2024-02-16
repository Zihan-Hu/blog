import path from 'node:path'
import { spawnSync } from 'node:child_process'
import { fileURLToPath } from 'node:url'
import process from 'node:process'
import { readDirDeepSync } from 'read-dir-deep'
import consola from 'consola'

const __filename = fileURLToPath(import.meta.url)
const __dirname = path.dirname(__filename)

const FILTER = [
  '+build/c++14',
  '-build/namespaces',
  '-legal/copyright',
  '-runtime/int',
  '-runtime/string',
].join(',')

function check(file: string) {
  return spawnSync('cpplint', [`--filter=${FILTER}`, file])
}

const SUFFIXS = ['.cpp', '.h', '.hpp']
const needCheck = (file: string) => SUFFIXS.some(s => file.endsWith(s))

function main() {
  const root = path.resolve(__dirname, '../../source')
  const files = readDirDeepSync(root, { absolute: true }).filter(needCheck)
  let errors = 0

  for (const file of files) {
    const p = check(file)
    if (p.status) {
      consola.error(p.stderr.toString())
      ++errors
    }
  }

  if (errors)
    consola.info(`共发现 ${errors} 个错误`)
  return errors ? 1 : 0
}

process.exit(main())
