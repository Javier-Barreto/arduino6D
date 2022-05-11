const { SerialPort, ReadlineParser } = require('serialport');

const port = new SerialPort({
    path: 'COM3',
    baudRate: 9600,
});

let cont = 1;
let array = new Array();

const parser = new ReadlineParser({ delimiter: '\r\n' });
port.pipe(parser);
parser.on('data', function (temp) {
    array.push({ "temperatura": temp });
    if (cont == 10) {
        let print = JSON.stringify({ array });
        print = JSON.parse(print);
        console.log(print);

        array.forEach(temp => {
            console.log(temp.valor);
        });

        array = [];
        cont = 0;
    }
    cont++;
})