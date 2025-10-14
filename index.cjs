'use strict';

var $import = require('bindings');

const addon = $import('main');
console.log(addon.hello()); // 'world'
