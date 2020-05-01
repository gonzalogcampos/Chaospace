#------------------- NOTA DE GONZALO -----------------------
#    De momento como no tenemos mucho codigo podemos
# compilar todos los .cpp en un unico binario (modulos.a)
# pero supongo que lo suyo seria crear varios binarios segun
# grupos para agilizar la compilacion.


#Especificar donde se encuentran los ficheros cpp a compilar
target_sources(modulos PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/Components/Ai.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Components/Controller.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Components/Physics.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Components/Life.cpp"

    "${CMAKE_CURRENT_SOURCE_DIR}/GameObjects/Bullet.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/GameObjects/GameObject.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/GameObjects/Asteroid.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/GameObjects/Npc.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/GameObjects/Player.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/GameObjects/PowerUp.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/GameObjects/Ship.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/GameObjects/EmptyAnimation.cpp"

    "${CMAKE_CURRENT_SOURCE_DIR}/GUI/Hud.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/GUI/Interface.cpp"

    "${CMAKE_CURRENT_SOURCE_DIR}/State/PlayState.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/State/TestState.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/State/MenuState.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/State/FinalState.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/State/NextLevelState.cpp"

    "${CMAKE_CURRENT_SOURCE_DIR}/Menus/Menu.cpp"

    "${CMAKE_CURRENT_SOURCE_DIR}/Render/Render.cpp"

    "${CMAKE_CURRENT_SOURCE_DIR}/Game.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Map.cpp"


    "${CMAKE_CURRENT_SOURCE_DIR}/TinyXML/tinyxml2.cpp"
)

#Y donde se encuentran los .h
target_include_directories(modulos PUBLIC 
    "${CMAKE_CURRENT_SOURCE_DIR}/Components"
    "${CMAKE_CURRENT_SOURCE_DIR}/GameObjects"
    "${CMAKE_CURRENT_SOURCE_DIR}/GUI"
    "${CMAKE_CURRENT_SOURCE_DIR}/State"
    "${CMAKE_CURRENT_SOURCE_DIR}/Render"
    "${CMAKE_CURRENT_SOURCE_DIR}/Menus"
    "${CMAKE_CURRENT_SOURCE_DIR}/TinyXML"
    "${CMAKE_CURRENT_SOURCE_DIR}"
)

