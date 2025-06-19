cmake_minimum_required(VERSION 3.26)
project(2048_Game C)

set(CMAKE_C_STANDARD 99)

# 콘솔 애플리케이션으로 설정 (Windows)
if(WIN32)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -mconsole")
endif()

add_executable(2048_Game 
    main.c 
    initBoard_1313.c 
    generateTile_1310.c 
    moveTiles_1315.c 
    mergeTiles_1308.c 
    checkGameOver_1310.c
    printboard_1308.c
)

# Windows에서 콘솔 서브시스템 사용
if(WIN32)
    set_target_properties(2048_Game PROPERTIES
        WIN32_EXECUTABLE FALSE
    )
endif()
