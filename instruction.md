# setup

- save "libbgi.a" file in MinGW\lib folder

***

# For "running cycle.cpp"

### To build the source

- go to terminal
- enter the follwing command
> g++ "running cycle.cpp" -o "..\bin\running cycle.exe" -Wl,"..\lib\libbgi.a" -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32

### To run the file

> running cycle.exe

***

# For "seven segment.cpp"

### To build the source

- go to terminal
- enter the follwing command
> g++ "seven segment.cpp" -o "..\bin\seven segment.exe" -Wl,"..\lib\libbgi.a" -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32

### To run the file

> seven segment.exe

***

# For "minipaint.cpp"

### To build the source

- go to terminal
- enter the follwing command
> g++ "minipaint.cpp" -o "..\bin\minipaint.exe" -Wl,"..\lib\libbgi.a" -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32

### To run the file

> minipaint.exe

***
