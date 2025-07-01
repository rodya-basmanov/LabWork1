# LabWork1
## Author
Basmanov Rodion group B81-mm
## Contacts
st135699@stdudent.spbu.ru

## Description
A program for image processing using parallel computing based on OpenMP:
- Rotating images left and right
- Applying Gaussian blur

## Build
```
make
```

## Run
```
./image [options]
```

### Options
```
-t, --threads <number>   Set the number of threads (default: maximum available)
-s, --sequential         Run sequential version
-p, --parallel           Run parallel version (default)
-b, --both               Run both versions for comparison
-h, --help               Show help
```

### Example
```
./image -b -t 4
```