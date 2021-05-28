# Node.js  
▪️ The essentials of Node.js

## Node Globals

### ▪️ The global object
```let hello = "Hello World From NODE JS";

console.log(hello);
```

### ▪️ The require function
```const path = require("path");

console.log('The file name is ${path.basename(__filename)}');
```

### ▪️ Argument variable with process.argv
```console.log(process.argv);```
```
const [, , firstName, lastName] = process.argv;

console.log('Your name is ${firstName} ${lastName}');
```
```
const grab = flag => {
  let indexAfterFlag = process.argv.indexOf(flag) + 1;
  return process.argv[indexAfterFlag]'
 };
 
 const greeting = grab("--greeting');
 const user = grab("--user");
 
 console.log('${greeting} ${user}');
 ```
 ### ▪️ Standard output and input
 ```
 process.stdout.write("Hello ");
 process.stdout.write("World \n\n\n");
 ```
 ```
const questions = [
  "What is your name?",
  "What would you rather be doing?",
  "What is your preferred programming language?"
];

const ask = (i = 0) => {
  process.stdout.write(`\n\n\n ${questions[i]}`);
  process.stdout.write(` > `);
};

ask();

const answers = [];
process.stdin.on("data", data => {
  answers.push(data.toString().trim());

  if (answers.length < questions.length) {
    ask(answers.length);
  } else {
    process.exit();
  }
});

process.on("exit", () => {
  const [name, activity, lang] = answers;
  console.log(`
  
Thank you for your anwsers.

Go ${activity} ${name} you can write ${lang} code later!!!

  
  `);
});

   ```
   
### ▪️ Creating a delay with setTimeout
```
const waitTime = 3000;
console.log(`setting a ${waitTime / 1000} second delay`);

const timerFinished = () => console.log("done");

setTimeout(timerFinished, waitTime);
```

### ▪️ Incorporate setInterval
```
const waitTime = 5000;
const waitInterval = 500;
let currentTime = 0;

const incTime = () => {
  currentTime += waitInterval;
  const p = Math.floor((currentTime / waitTime) * 100);
};

console.log(`setting a ${waitTime / 1000} second delay`);

const timerFinished = () => {
  clearInterval(interval);
  console.log("done");
};

const interval = setInterval(incTime, waitInterval);
setTimeout(timerFinished, waitTime);
```

### ▪️ Report progress with setInterval
```
const waitTime = 5000;
const waitInterval = 500;
let currentTime = 0;

const incTime = () => {
  currentTime += waitInterval;
  const p = Math.floor((currentTime / waitTime) * 100);
};

console.log(`setting a ${waitTime / 1000} second delay`);

const timerFinished = () => {
  clearInterval(interval);
  console.log("done");
};

const interval = setInterval(incTime, waitInterval);
setTimeout(timerFinished, waitTime);
```
   
