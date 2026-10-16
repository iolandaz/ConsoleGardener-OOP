cmake_minimum_required(VERSION 3.30)
project(TP_POO_25)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)

add_executable(TP_POO_25
        main.cpp
        src/controlador/Controlador.cpp
        src/interface/Interface.cpp
        src/modelo/Jardim.cpp
        src/modelo/Jardineiro.cpp
        src/modelo/Solo.cpp
        src/interface/comandos/Comando.cpp
        src/interface/comandos/ComandoApaga.cpp
        src/interface/comandos/ComandoAvanca.cpp
        src/interface/comandos/ComandoColhe.cpp
        src/interface/comandos/ComandoCompra.cpp
        src/interface/comandos/ComandoCriarJardim.cpp
        src/interface/comandos/ComandoEntra.cpp
        src/interface/comandos/ComandoExecuta.cpp
        src/interface/comandos/ComandoFim.cpp
        src/interface/comandos/ComandoGrava.cpp
        src/interface/comandos/ComandoLarga.cpp
        src/interface/comandos/ComandoListaArea.cpp
        src/interface/comandos/ComandoListaFerramentas.cpp
        src/interface/comandos/ComandoListaPlanta.cpp
        src/interface/comandos/ComandoListaPlantas.cpp
        src/interface/comandos/ComandoListaSolo.cpp
        src/interface/comandos/ComandoMovimentoBaixo.cpp
        src/interface/comandos/ComandoMovimentoCima.cpp
        src/interface/comandos/ComandoMovimentoDireita.cpp
        src/interface/comandos/ComandoMovimentoEsquerda.cpp
        src/interface/comandos/ComandoPega.cpp
        src/interface/comandos/ComandoPlanta.cpp
        src/interface/comandos/ComandoRecupera.cpp
        src/interface/comandos/ComandoSai.cpp
        src/modelo/Settings.cpp
        src/modelo/ferramentas/TipoFerramentas.cpp
        src/modelo/ferramentas/Ferramenta.cpp
        src/modelo/ferramentas/FerramentaZ.cpp
        src/modelo/ferramentas/Regador.cpp
        src/modelo/ferramentas/Tesoura.cpp
        src/modelo/ferramentas/Adubo.cpp
        src/modelo/Tempo.cpp
        src/modelo/plantas/Planta.cpp
        src/modelo/plantas/Roseira.cpp
        src/modelo/plantas/Cacto.cpp
        src/modelo/plantas/Exotica.cpp
        src/modelo/plantas/TipoPlanta.cpp
        src/modelo/plantas/ErvaDaninha.cpp)
