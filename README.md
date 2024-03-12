# wasmLoadLocalFiles
Proof of concept on how a single file emscripten/js .html can be setup to load local files 
Since mobile browser projects (e.g. javascript, emscripten compiled programs to .wasm) cannot normally load local files, the use of .wasm as a platform independent means to distributing projects to run locally on mobile devices is limited to .wasm files that don't load local files. Such limitation prevents projects such as .wasm compiled game engines/IDEs from loading local code to run. This project demonstrates how emscripten can be combined with javascript into a single file that can be used to load local files on mobile or non-mobile device. 

# strategy and expected restult
1. use emscripten to compile program code of interest (e.g. wasmJSReadFile.c in this repository):
   
   ./emcc [emcc on Windows] .wasmJSReadFile.c -o wasmJSReadFile.html -s SINGLE_FILE -s ENVIRONMENT=web -s EXPORTED_RUNTIME_METHODS="['FS']"
   
3. add custom javascript code (e.g. jsReadLocalFile.txt) to the .html generated above (e.g. wasmJSReadFile.html) which asks the user to
   choose a file to upload via javascript and which subsequently uses emscripten's Module.FS api to write the uploaded local file
   (e.g. test.lua) into emscripten's virtual file system so that it can be used by the compiled .wasm code. This proof of concept project
   relies on the fact that local files can be loaded by browser projects if the user themsevles chooses those local files and that
   emscripten's Module.FS api allows browser javascript to write into emscripten's virtual filesystem that .wasm code can access.
4. Place the test file (e.g. test.lua) somewhere in a directory on the local device
5. Open .html (e.g. wasmJSReadFile.html) in a mobile or non-mobile web browser and click on the "Choose File" button to select the test.lua file
6. Emscripten demo web page displays result (e.g. contents of test.lua) in canvas in the middle of the webpage simulating stdout

# changes for production use
The above strategy packages all of the code into a single file .html (base64 encoded .wasm, .javascript code to interact with .wasm and
.html code to display webpage) and includes default enscripten .html code in doing so. The default emscripten .html code renders a useful demo webpage but would not likely be needed for production .wasm projects needing to upload local files. Instead, if the demo webpage is not needed,
change the compiled output to a javascript file instead (e.g.):

./emcc [emcc on Windows] .wasmJSReadFile.c -o wasmJSReadFile.js -s SINGLE_FILE -s ENVIRONMENT=web -s EXPORTED_RUNTIME_METHODS="['FS']"

and then add the javascript output file (e.g. wasmJSReadFile.js) to a <script> in your own .html file. 

# acknowledgements
Thanks to @morew4rd for encouraging me to create this proof of concept
Thanks to @akkartik, @zbtnot, and @sbc100 for tips on how to create this project 😊
