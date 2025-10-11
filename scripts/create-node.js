const existsSync = require('fs').existsSync;
const execSync = require('child_process').execSync;

if (!existsSync('node')) execSync("ln -s `which node` node");