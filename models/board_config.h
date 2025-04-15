#ifndef BOARD_CONFIG_H
#define BOARD_CONFIG_H

#include <string>

class BoardConfig {
public:
    // File and Directory Paths
    static const std::string BOARDS_DIRECTORY;
    static const std::string GLOBAL_DATA_FILE;

    // Command Strings
    static const std::string CMD_CREATE;
    static const std::string CMD_SELECT;
    static const std::string CMD_DESELECT;
    static const std::string CMD_DELETE;
    static const std::string CMD_UPDATE;

    // JSON Keys
    static const std::string KEY_NAME;
    static const std::string KEY_CURRENT_BOARD;
    static const std::string KEY_DIRECTORY;

    // Error Messages
    static const std::string ERR_FILE_CREATE;
    static const std::string ERR_FILE_NOT_FOUND;
    static const std::string ERR_BOARD_NOT_EXIST;
    static const std::string ERR_BOARD_SAVE;
    static const std::string ERR_INVALID_COMMAND;
    static const std::string ERR_BOARD_DELETION;
};

inline const std::string BoardConfig::BOARDS_DIRECTORY = "boards/";
inline const std::string BoardConfig::GLOBAL_DATA_FILE = "data.json";

// Command Strings
inline const std::string BoardConfig::CMD_CREATE = "create";
inline const std::string BoardConfig::CMD_SELECT = "select";
inline const std::string BoardConfig::CMD_DESELECT = "deselect";
inline const std::string BoardConfig::CMD_DELETE = "delete";
inline const std::string BoardConfig::CMD_UPDATE = "update";

// JSON Keys
inline const std::string BoardConfig::KEY_NAME = "name";
inline const std::string BoardConfig::KEY_CURRENT_BOARD = "current_board";
inline const std::string BoardConfig::KEY_DIRECTORY = "directory";

// Error Messages
inline const std::string BoardConfig::ERR_FILE_CREATE = "File cannot be created";
inline const std::string BoardConfig::ERR_FILE_NOT_FOUND = "File not found";
inline const std::string BoardConfig::ERR_BOARD_NOT_EXIST = "Board does not exist";
inline const std::string BoardConfig::ERR_BOARD_SAVE = "Board couldn't be saved";
inline const std::string BoardConfig::ERR_INVALID_COMMAND = " is not a valid command";
inline const std::string BoardConfig::ERR_BOARD_DELETION = "Board deletion has failed";

#endif // BOARD_CONFIG_H
