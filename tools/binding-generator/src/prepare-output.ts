import * as Fs from 'fs';
import * as Path from 'path';
import * as rimraf from 'rimraf';

import outputDirectory from './output';

export default (muiSrc: muiSrc) => {
  if (Fs.existsSync(Path.join(outputDirectory, 'reason', muiSrc))) {
    rimraf.sync(Path.join(outputDirectory, 'reason', muiSrc));
  }
  const requiredFolders = ['reason', Path.join('reason', muiSrc)];
  requiredFolders.forEach((folder) => {
    const path = Path.join(outputDirectory, folder);
    if (!Fs.existsSync(path)) {
      Fs.mkdirSync(path);
    }
  });
};
