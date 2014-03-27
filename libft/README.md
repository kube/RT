LibFt
=====
> "Arbre renversé par le vent avait plus de branches que de racines."

##Construction
This lib is separated in 9 sub-modules, the goal is to use what is really necessary in your program :

|||
|---|---|
|**Colors**|Handles colors blend modes, complementaty color, and fade.|
|**Convert**|Basic conversions on numbers and strings, and a basic hash function.|
|**Hashmap**|Generic simple Hashmap to allocate variables dynamically, and be able to search in it.|
|**Input**|Stuff to get user or file input.|
|**Lists**|Lists structures, and functions to handle them.|
|**Math**|Vectors, Infinite Numbers, Trigonometry, and basics.|
|**Memory**|Functions to handle memory.|
|**Print**|Print texts to terminal.|
|**Strings**|Handle strings, make searches in them, check properties.|

##Compilation
>Beware of the modules dependencies, that are not handled for now

|Rule|Description|
|----|-----------|
|`usemath`|Use <math.h> for Math module, vectors properties. Will be faster.|
||**Substractive compilation**|
|`nohashmap`|Will not compile *hashmaps* module|
|`nocolors`|Will not compile *colors* module|
|`nolists`|Will not compile *lists* module|
|`nomath`|Will not compile *math* module|
|`noprint`|Will not compile *print* module|
|`noconvert`|Will not compile *convert* module|
|`nostrings`|Will not compile *strings* module|
|`nomemory`|Will not compile *memory* module|
|`noinput`|Will not compile *input* module|
||**Additive compilation**|
|`nothing`|Remove all modules from compilation|
|`addcolors`|Will add *colors* module to compilation|
|`addlists`|Will add *lists* module to compilation|
|`addmath`|Will add *math* module to compilation|
|`addprint`|Will add *print* module to compilation|
|`addconvert`|Will add *convert* module to compilation|
|`addstrings`|Will add *strings* module to compilation|
|`addmemory`|Will add *memory* module to compilation|
|`addinput`|Will add *input* module to compilation|


Compilation examples :
```sh
#Will compile the lib with <math.h> functions
make usemath all
```
```sh
#Will compile the lib without print and input modules
make noprint noinput all
```
```sh
#Will compile the lib with only memory and math modules
make nothing addmemory addmath all
```

##Things to do
* Fix Makefile rules issues (Add selective rules and make all compiles everything)
* Add Vectors Operations
* Better Sin and Cos by putting angle to [-π;π] interval.
* Check Hashmaps functions
* Normalize Inifinite Addition/Substraction
* Add Infinite Multiplication
* Handle zero in Infinite Numbers
* Create Generic Lists
