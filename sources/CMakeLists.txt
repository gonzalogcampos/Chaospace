#Especificar donde se encuentran los ficheros cpp a compilar
target_sources(libModulos PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/src/Ai.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/Bullet.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/Controller.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/Game.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/Hud.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/Interface.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/Life.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/Npc.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/Map.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/Object.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/Player.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/PowerUp.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/Ship.cpp"
)

#Y donde se encuentran los .h
target_include_directories(libModulos PUBLIC 
"${CMAKE_CURRENT_SOURCE_DIR}/headers"
)

