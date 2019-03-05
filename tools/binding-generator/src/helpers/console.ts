import * as util from 'util';

export const colors = {
    reset: '\x1b[0m',
    yellow: '\x1b[33m',
    black: '\x1b[30m',
    red: '\x1b[31m',
    green: '\x1b[32m',
    blue: '\x1b[34m',
    magenta: '\x1b[35m',
    cyan: '\x1b[36m',
    white: '\x1b[37m',
};

const logColor = (color: string, log: any) => console.log(`${color}%s${colors.reset}`, log);

export const warn = (log: any) => logColor(colors.yellow, log);
export const error = (log: any) => logColor(colors.red, log);
export const info = (log: any) => logColor(colors.cyan, log);
export const log = (log: any) => console.log(util.inspect(log, false, null));