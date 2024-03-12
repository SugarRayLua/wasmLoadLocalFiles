# wasmLoadLocalFiles
Proof of concept on how a single file emscripten/js .html can be setup to load local files 
Since mobile browser projects (e.g. javascript, emscripten compiled programs to .wasm) cannot normally load local files, the use of .wasm as a platform independent means to distributing projects to run locally on mobile devices is limited to .wasm files that don't load local files. Such limitation prevents projects such as .wasm compiled game engines/IDEs from loading local code to run. This project demonstrates how emscripten can be combined with javascript into a single file that can be used to load local files on mobile or non-mobile device. 

# strategy
1. use emscripten to compile program code of interest (e.g. wasmJSReadFile.c in this repository)
   ./emcc [emcc on Windows] .wasmJSReadFile.c -o wasmJSReadFile.html -s SINGLE_FILE -s ENVIRONMENT=web -s EXPORTED_RUNTIME_METHODS="['FS']"
2. add custom javascript code (e.g. jsReadLocalFile.txt) to .html generated above (e.g. wasmJSReadFile.html) which ask the user to
   choose a file to upload with javascript that will subsequently use emscripten's Module



