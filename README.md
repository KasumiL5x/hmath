# hmath
> hmath is a lightweight mathematics library. It can be included in projects without any external dependencies, with minimal work required. It is partially based on [GeometricTools](https://www.geometrictools.com/Source/Mathematics.html).

Unlike [ccmath](https://github.com/KasumiL5x/ccmath), which is focused on simplicity to avoid mistakes (e.g. automatically initializing everything), hmath is focused on quality and speed. hmath also opts for a global-function based system rather than being member-function based. For instance, operations between vectors are done using global functions rather than having functions exist within the vectors themselves. This is the preferred style for many mathematicians, as it better mirrors mathematical notation written by hand.

## Usage
To use hmath in your own project, download the source code, and extract the `src/hmath` folder. This folder must be appended to your compiler's include directories. You can then include any file from the hmath directory into your project.

## Notes
A number of classes are specializations of template base classes. For instance, `Vector3` is a specialization of `Vector`. All shared functionality is defined in the base class, and specific functionality is defined in the derived headers. For instance, functions including 3D vectors are defined in the `Vector3.hpp` header.

Most functions are global rather than class-based. This is to better match mathematical notation. For instance, the code below computes the cross product of two 3D vectors:

```cpp
#include <hmath/Vector3.hpp>
 
const hm::Vector3 v0 = {0.0f, 1.0f, 0.0f};
const hm::Vector3 v1 = {1.0f, 0.0f, 0.0f};
const hm::Vector3 v2 = hm::cross(v1, v0);
```