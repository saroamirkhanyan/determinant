const fs = require('fs');

const OUTPUT_FILE_NAME = 'input-example';
const SIZE = 13;
const MIN_VALUE = 1;
const MAX_VALUE = 3;

const file = fs.createWriteStream(OUTPUT_FILE_NAME);

const random = (min, max) => Math.floor(Math.random() * (max - min) + min);

file.write(SIZE.toString());
file.write('\n');
for(let i = 0; i < SIZE * SIZE; i++) {
        file.write(random(MIN_VALUE, MAX_VALUE).toString());
        file.write('\n');
}
file.end();
