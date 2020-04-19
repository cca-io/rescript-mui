import * as yargs from 'yargs';

const args = yargs
  .option('src', {
    describe: 'mui source',
    choices: ['core', 'lab'],
  })
  .demandOption(['src'], 'Please provide src argument')
  .help().argv;
const muiSrc = <muiSrc>args.src;

export default muiSrc;
