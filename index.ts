import { keyTap } from 'robotjs';
import { ReadlineParser, SerialPort } from 'serialport';

// Path to the serial port. E.g. /dev/... on unix or COM3 on Windows
const devicePath = '/dev/path/to/arduino';

console.log('Connecting to Arduino...');
const port = new SerialPort({
  path: devicePath,
  baudRate: 9600,
});
console.log('Connected.');

const parser = new ReadlineParser();
port.pipe(parser);
parser.on('data', (chunk) => {
  try {
    const data = JSON.parse(chunk);

    if (data?.direction) {
      const isVolumeUp = data?.direction === 'CW';
      keyTap(isVolumeUp ? 'audio_vol_up' : 'audio_vol_down');
      console.log('Volume', isVolumeUp ? 'up' : 'down');
    }

    if (data?.button === 'released') {
      keyTap('audio_mute');
      console.log('Volume toggle');
    }
  } catch {
    console.error('error while parsing', chunk);
  }
});
