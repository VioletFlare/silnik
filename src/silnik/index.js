const addon = require('bindings')('main');

console.log(addon.hello()); // 'world'