# Eyon Programming Language
![https://badgen.net/badge/icon/windows?icon=windows&label](https://badgen.net/badge/icon/windows?icon=windows&label)
![https://badgen.net/badge/icon/github?icon=github&label](https://badgen.net/badge/icon/github?icon=github&label)

## Introduction
Eyon Programming Language is an interpretive language based on Yolang and Eytion;  
In Eyon, you will see the similarities with Yolang and Eytion.  
However, he is more excellent and efficient than Yolang and Eytion

## License
This project uses MIT license  
You can view the license of this project through the following this [link](LICENSE)

## How to USE?
Eyon is divided into two types: Build and Release  

**Release** version You need to select a version by yourself through the "Release" on the right side of the project, where you can obtain the entire software package (except for the executable file)  

**Build** is the result automatically compiled through Action (only executable files).  
The result may be unstable or even have serious vulnerabilities.  
Please use it with caution; 
Of course, in most cases you can use the Build version to try something new.  
After you obtain the files of Build version, you need to replace the executable files in the original software package of Eyon (named "eyon", and the suffix depends on the system)

## Demo (future)
hello world
```rust
use std::IO;

IO::println("hello world");

let text: string = "hello world!!!";
IO::println(text);
```
function
```rust
let io: package = use std::IO;
// or: let io = use std::IO;

func int32 add(a: int32, b: int32) {
    return a + b;
    // or: a + b
}

io.print(add(4, 5));
```
struct
```rust
use std::IO;

struct A {
    public mem_a: int32;
    private mem_b: string;
};
impl for A {
    string getMemB() {
        mem_b
        // or: return mem_b;
    }
};
```

## Contributors
### [**PowerAngelXD**](https://github.com/PowerAngelXD)  
**Initiator of the project**  
### [**FZZKill**](https://github.com/FZZkill)  
**The most active people who help improve the project**
### [**This-is-XiaoDeng**](https://github.com/This-is-XiaoDeng) 
**Help the Release version of this project compile the Linux version**