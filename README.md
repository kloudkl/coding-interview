coding-interview
================
Coding interview data structure and algorithm

References
================
1. [Introduction to Algorithms](http://www.amazon.com/Introduction-Algorithms-Thomas-H-Cormen/dp/0262033844/ref=sr_1_1?s=books&ie=UTF8&qid=1388838368&sr=1-1)
2. [Cracking the Coding Interview: 150 Programming Questions and Solutions](http://www.amazon.com/Cracking-Coding-Interview-Programming-Questions/dp/098478280X/ref=sr_1_1?s=books&ie=UTF8&qid=1388838468&sr=1-1)
3. [Elements of Programming Interviews: 300 Questions and Solutions](http://www.amazon.com/Elements-Programming-Interviews-Questions-Solutions/dp/1479274836/ref=sr_1_4?s=books&ie=UTF8&qid=1388838468&sr=1-4)

[How to Install GCC 4.8 via PPA in Ubuntu 12.04, 13.04, 10.04](http://ubuntuhandbook.org/index.php/2013/08/install-gcc-4-8-via-ppa-in-ubuntu-12-04-13-04/)
============================================================
1. Press Ctrl+Alt+T on your keyboard to open terminal. When it opens, run below commands to add the ppa:
```bash
sudo add-apt-repository ppa:ubuntu-toolchain-r/test
```

2. Then install gcc 4.8 and g++ 4.8:
```bash
sudo apt-get update
sudo apt-get install gcc-4.8 g++-4.8
```

3. Once installed, run following commands one by one to use gcc 4.8 instead of previous version.
```bash
sudo update-alternatives --remove-all gcc 
sudo update-alternatives --remove-all g++
sudo update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-4.8 20
sudo update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-4.8 20
sudo update-alternatives --config gcc
sudo update-alternatives --config g++
```

4. Now you have the gcc 4.8 with c++11 complete feature in your system. Check out by:
```bash
gcc --version
gcc (Ubuntu 4.8.1-2ubuntu1~13.04) 4.8.1
Copyright (C) 2013 Free Software Foundation, Inc.
This is free software; see the source for copying conditions. There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
```

[Enabling C++11 in Eclipse Juno/Kepler CDT](http://stackoverflow.com/questions/17457069/enabling-c11-in-eclipse-juno-kepler-cdt)
=========================================
There's two things you have to do, first you need to setup your compiler, then you need to setup CDT's language processor. Since you didn't mention which compiler you're using, I'll assume it's GCC but the steps will be similar for other compilers. (Note that you need a compiler that supports C++11, of course.)

Setting up the compiler is fairly straightforward:

1. Right click your project and click Properties
2. Under C/C++ Build click Settings
3. Under GCC C++ Compiler, click Miscellaneous
4. In the Other Flags box, append "-std=c++11" to the list of tokens.
5. Click Apply and OK
At this point you should be able to rebuild your project and get it to run. But CDT still may show errors for C++11 includes. Here's how you can resolve that:

1. Right click your project and click Properties
2. Under C/C++ General click "Preprocessor Include Paths, Macros"
3. Select the Providers tab
4. There should be an item in the list that says something like "GCC Built in Compiler Settings". Select this entry.
5. Under the list there's an box that says "Command to get compiler specs." Append "-std=c++11" to this.
6. Click Apply and then OK.
7. Back in your Eclipse workspace, select the Project Menu, C/C++ Index, and click "Re-resolve unresolved includes."
