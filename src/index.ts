import $import from 'bindings';

const addon = $import('main');

console.log(addon.hello()); // 'world'