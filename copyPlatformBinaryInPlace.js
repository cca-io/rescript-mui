#!/usr/bin/env node

console.log('*');
console.log('* Copying ppx_withStyles from binaries.');
console.log('* This script has been copied & modified from https://github.com/mhallin/graphql_ppx');
console.log('*');

var fs = require('fs');

var arch = process.arch;
var platform = process.platform;

if (arch === 'ia32') {
    arch = 'x86';
}

if (platform === 'win32') {
    platform = 'win';
}

var filename = 'bin/ppx_withStyles-' + platform + '-' + arch;
var supported = fs.existsSync(filename);

if (!supported) {
    console.error('ppx_withStyles does not support this platform :(');
    console.error('');
    console.error('ppx_withStyles comes prepacked as built binaries to avoid large');
    console.error('dependencies at build-time.');
    console.error('');
    console.error('If you want ppx_withStyles to support this platform natively,');
    console.error('please open an issue at our repository, linked above. Please');
    console.error('specify that you are on the ' + platform + ' platform,');
    console.error('on the ' + arch + ' architecture.');

    process.exit();
}

if (!fs.existsSync('ppx')) {
    copyFileSync(filename, 'ppx_withStyles');
    fs.chmodSync('ppx_withStyles', 0755);
}

function copyFileSync(source, dest) {
    if (typeof fs.copyFileSync === 'function') {
        fs.copyFileSync(source, dest);
    } else {
        fs.writeFileSync(dest, fs.readFileSync(source));
    }
}
