#!/usr/bin/env node

var fs = require('fs');

var arch = process.arch;
var platform = process.platform;

if (arch === 'ia32') {
  arch = 'x86';
}

if (platform === 'win32') {
  platform = 'win';
}

copyBinary(
  'bin/rescript_material_ui_ppx-' + platform + '-' + arch + '.exe',
  'ppx',
);
copyBinary(
  'bin/rescript_material_ui_ppx-' + platform + '-' + arch + '.exe',
  'ppx6',
);

function copyBinary(filename, destFilename) {
  var supported = fs.existsSync(filename);

  if (!supported) {
    console.error(
      [
        'rescript_material_ui_ppx does not support this platform :(',
        '',
        'rescript_material_ui_ppx comes prepacked as built binaries to avoid large dependencies at build-time.',
        '',
        'If you want rescript_material_ui_ppx to support this platform natively,',
        'please open an issue at our repository, linked above. Please',
        'specify that you are on the ' + platform + ' platform,',
        'on the ' + arch + ' architecture.',
      ].join('\n'),
    );

    process.exit(1);
  }

  if (!fs.existsSync(destFilename)) {
    copyFileSync(filename, destFilename);
    fs.chmodSync(destFilename, 0755);
  }

  var destFilenameExe = destFilename + '.exe';
  if (!fs.existsSync(destFilenameExe)) {
    copyFileSync(filename, destFilenameExe);
    fs.chmodSync(destFilenameExe, 0755);
  }
}

function copyFileSync(source, dest) {
  if (typeof fs.copyFileSync === 'function') {
    fs.copyFileSync(source, dest);
  } else {
    fs.writeFileSync(dest, fs.readFileSync(source));
  }
}
