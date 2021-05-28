# NPM
▪️ Understanding the Node Package Manager, it comes pre-installed with Node.js.

## What are packages and npm ? 
### ▪️ Dependencies
- packages that are used in all projects and come with a package.json file, which is basically the map of your program. It tells you who created it, the version, and the package that needs to be installed. 
### ▪️ Package, Module, Dependency
- They're a file or multiple files combined together to form a package that represents a specific function.
- NPMJS.com, you can search this directory of packages for any function to add to a project. For example, to add simple syntax for displaying dates on your application, you can do a search for dates and then install the moment package.
- The idea behind having this package directory and NPM is to build lightweight projects that can be easily shared across development teams and install the dependencies or packages locally on our machines when we use the project. It allows to free our resources locally and install only what we need.

## ▪️ Creating the package.jsn files. 
- The first thing we need to do is create the package.jsn files, so the map for npm. So let's go ahead and bring up the terminal in VS Code, so I'm gonna click on "View", "Terminal", and what I'm gonna do next is npm init, which is the base command to initialize a new package.jsn file.

## ▪️ Adding Node Packages
### The difference between downloading locally and globally
- When a package is installed locally, it is installed on your project's directory. When it is installed globally, it will be installed in your system, available to all projects.
- npm install babel-cli babel-preset-stage-0 babel-preset-es2015 --save-dev

## ▪️ Managing global Directory
### Commands
- you use -g or -global
- npm install -g react

## ▪️ Updating a package
### Commands
- To check if your NPMS are outdated or not, you use:  npm outdated

## ▪️ Removing a package
### Commands
- To uninstall, you use: npm uninstall

## ▪️ Semantic versioning
- The first number is the major release, the second number is the minor release, and the third number is the patch release
### Major release
- A full new version or software
### Minor release
- Adding new functions to the major release or a new tool
### Patch release
- Patches and fixes for bugs...etc
### Caret
- The default when installing new packages and it means that when you and another developer installs the dependencies, it means that NPM will install any recent version available
### Tilde 
- It means we wont install any versions beyond that number

## ▪️ package-lock.json
- It's automatically generated for any operations where npm modifies either the node_modules tree, or package. json . It describes the exact tree that was generated, such that subsequent installs are able to generate identical trees, regardless of intermediate dependency updates.

## ▪️ Working with an npm cache
- Clearing your npm cache should always be part of your troubleshooting steps when working with modueles and not realy understanding what's happening. 
### Commands
- You can use: npm cache verify : it basically runs a report that verifies your cache
- To clean your cache, you use: npm cache clean --force : you have to force it otherwise it won't work.

## ▪️ Run and npm audit
- Whenever you install a new package, the command npm audit runs automatically and tells you if there are any issues with the package. 

## Scripting in package.json
- docs.npmjs.com/miscc/scripts


