# IDEs & Compilers
## Contents
- [Intro](#intro)
- [Topics](#topics)
  - [Visual Studio](#visual-studio)
    - [Line Numbers](#line-numbers)
    - [Replace Tabs with Spaces](#replace-tabs-with-spaces)
    - [Indentation Settings](#indentation-settings)
    - [Pause Before Program Termination](#pause-before-program-termination)
  - [XCode](#xcode)
  - [g++](#g++)
- [Sources Used](#sources-used)

### Intro
This page serves as a helpful reference on IDEs (integrated development environments) such as Visual Studio and XCode, and compilers 
such as g++.

More may be added on this page if deemed necessary. If there are any errors or issues just let me know either via email, during 
lecture, or during the SI session.

NOTE: I realize some of you guys might have not worked on functions in CS 120. If you have, however, 
the resource is within the topic list. Otherwise, you may want to head over to a tutorial site for help.

### Topics
Each topic provides common terminology and errors associated per topic.

#### Visual Studio
Below are tips and suggestions for when working with Visual Studio (2010 - 2013).

##### Line Numbers
This allows you to list the line numbers on the left while you're editing your code in Visual Studio. This is extremely useful, especially when 
you're debugging or get into larger projects and have a lot of code to work with.

Go to `Tools -> Options -> All Languages (or C/C++ if you only want it for that) -> General`, and under "Display" tick the option "Line Numbers".

##### Replace Tabs with Spaces
If you've ever opened or copied your code from Visual Studio into a program such as Notepad++ or Wordpad, chances are you've seen all your indentation 
as huge gaps. This is because text editing programs typically have their own definition for how big a tab press is.

Usually, the best way to fix this issue is by replacing tabs with spaces. You can either do this manually, or set up the text editor so it inserts 
spaces instead of a tab.

To do so, navigate to the same location as the line numbers, except instead of General you'll want to click "Tabs". 

You normally want to keep the tab and indent size the same. Common values are "2,2" and "4,4".

##### Indentation Settings
You can change how Visual Studio indents when you move to a new line (i.e. when you press enter in the text editor).

To change your indentation settings, navigate to the same location as where you change the tab settings (previous note).

Here's a link describing the differences in detail: http://blogs.msdn.com/b/zainnab/archive/2010/04/15/smart-vs-block-vs-none-the-indenting-smackdown-vstipedit0049.aspx

##### Pause Before Program Termination
There are several ways to do this. Firstly, I'll go over what a good solution for Visual Studio is, why using the most-suggested `system("pause");` 
is a bad idea, and a solution (for general purpose).

To remove the need to have a pause statement of any sort before your program terminates, do the following:

Go to `Project -> Configuration Properties -> Linker -> System` and from there change "SubSystem" to "Console (/SUBSYSTEM:CONSOLE)".

From here, you can press CTRL + F5 to compile and run your code (this runs your code without the debugger). If you run with debugging, the 
code will still terminate as before.

Props to http://www.cplusplus.com/forum/windows/120174/ from user Disch.

REST TBD.

##### 

#### XCode
TBD

#### g++
TBD

#### Sources Used
- 

-------------------------------------------------------------------------------

Copyright &copy; 2015 Joseph Greene <joeisgreene@csu.fullerton.edu>  
Released under [The MIT License] (http://opensource.org/licenses/MIT)  
Project located at <https://github.com/joegreene/CS_121_Fall_2014>