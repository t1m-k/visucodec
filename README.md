# VisuCodec aka ВижуКодек

## About

This project is designed for exploring coding theory and practical implementation of codecs.
It features **beautiful UI** for learning and
(*trying to create best practices*)
**C implementation** of encoding algorithms.

Our goal is to demonstrate different methods of
encoding and processing information,
starting from classic Caesar cipher,
moving through the ideas of Fano and Shannon
and concluding with modern coding theory, e.g. LDPC codes.


## Progress

Project is just starting now, but you still can use it or contribute!

**TODO list** is here:
- [x] Create base for developing (c + ui connection using states)
- [x] Test page
- [ ] Lesson base
- [ ] First real lesson


## Installation
If you want to develop this project on your machine, you need installed docker (or npm and emcc). The easiest way to start is Docker + VSCode with "Dev Containers" extension:

1. Fork this repo and clone **yours**. But if sure that you do not want to contribute, you may clone the original
2. Open project in VSCode, press `F1` and select `Dev Containers: Reopen in Container`
3. Install dependencies using `make install`
4. Run dev server using `make compile` and then `make run` in the project root folder.

## Contribution
If you did something you want to share with the original project, please follow these steps:

1. **Create new branch** for your changes:
    ```bash
    git checkout -b your-feature-short-name
    ```
2. **Ensure** your changes work correctly
3. **Commit changes** with a clear message and all files tracked:
    ```bash
    git add .
    git commit -m "feat: <short description here>"
    ```
4. **Push to your fork on GitHub** and open **Pull request** to the upstream (original repo)

## Thank you for reading this, enjoy!