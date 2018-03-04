const addon = require('./build/Release/node-factorial-cc');

exports.factorial = function (n) {

    return addon.factorial(n);
};