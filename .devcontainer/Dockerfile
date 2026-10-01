FROM mcr.microsoft.com/devcontainers/javascript-node:20

RUN apt-get update && apt-get install -y \
    git \
    python3 \
    build-essential \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /opt
RUN git clone https://github.com/emscripten-core/emsdk.git \
    && cd emsdk \
    && ./emsdk install latest \
    && ./emsdk activate latest

ENV EMSDK=/opt/emsdk
ENV EMSDK_NODE=/usr/local/bin/node
ENV PATH="/opt/emsdk:/opt/emsdk/upstream/emscripten:${PATH}"
ENV EM_CONFIG=/opt/emsdk/.emscripten
