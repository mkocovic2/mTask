#include "../include/mtask/board.h"
#include "../include/mtask/board_config.h"

Board::Board(std::string name) {
  this->entityName = name;
  commandHandler[BoardConfig::CMD_CREATE] = [this](std::string name) {
    return this->Create(name);
  };
  commandHandler[BoardConfig::CMD_SELECT] = [this](std::string name) {
    return this->SelectBoard(name);
  };
  commandHandler[BoardConfig::CMD_DESELECT] = [this](std::string name) {
    return this->DeselectBoard(name);
  };
  commandHandler[BoardConfig::CMD_DELETE] = [this](std::string name) {
    return this->Destroy();
  };
  commandHandler[BoardConfig::CMD_UPDATE] = [this](std::string name) {
    return this->Update();
  };
}

void Board::HandleCommand(std::string command, std::string name) {
  if (commandHandler.find(command) != commandHandler.end()) {
    commandHandler[command](name);
  } else {
    throw std::invalid_argument(command + BoardConfig::ERR_INVALID_COMMAND);
  }
}

void Board::Create(std::string boardName) {
  json boardObject;

  boardObject[boardName] = {{BoardConfig::KEY_NAME, boardName}};

  std::ofstream b_write(BoardConfig::BOARDS_DIRECTORY + boardName + ".json");
  if (!b_write.is_open()) {
    throw std::invalid_argument(BoardConfig::ERR_FILE_CREATE);
  }
  b_write << boardObject;
  b_write.close();

  json globalData;

  std::ifstream d_read(BoardConfig::GLOBAL_DATA_FILE);
  if (!d_read.is_open()) {
    throw std::invalid_argument(BoardConfig::ERR_BOARD_SAVE);
  }

  d_read >> globalData;
  globalData[boardName] = {{BoardConfig::KEY_NAME, boardName}};

  d_read.close();

  std::ofstream d_write(BoardConfig::GLOBAL_DATA_FILE);
  if (!d_write.is_open()) {
    throw std::invalid_argument(BoardConfig::ERR_BOARD_SAVE);
  }

  d_write << globalData;
  d_write.close();
}

void Board::SelectBoard(std::string board_name) {
  std::ifstream b_save(BoardConfig::GLOBAL_DATA_FILE);
  if (!b_save.is_open()) {
    throw std::invalid_argument(BoardConfig::ERR_FILE_NOT_FOUND);
  }

  json data;
  b_save >> data;
  b_save.close();

  if (data.contains(board_name) && data[board_name].is_object()) {
    data[BoardConfig::KEY_CURRENT_BOARD][BoardConfig::KEY_NAME] = board_name;
    std::cout << data[BoardConfig::KEY_CURRENT_BOARD][BoardConfig::KEY_NAME];
  } else {
    std::cerr << BoardConfig::ERR_BOARD_NOT_EXIST;
  }

  std::ofstream b_write(BoardConfig::GLOBAL_DATA_FILE);
  if (!b_write.is_open()) {
    throw std::invalid_argument(BoardConfig::ERR_FILE_NOT_FOUND);
  }
  b_write << data;

  b_write.close();
}

void Board::DeselectBoard(std::string boardName) {
  std::ifstream b_save(BoardConfig::GLOBAL_DATA_FILE);
  if (!b_save.is_open()) {
    throw std::invalid_argument(BoardConfig::ERR_FILE_NOT_FOUND);
  }

  json data;
  b_save >> data;

  if (data.contains(BoardConfig::KEY_CURRENT_BOARD) &&
      data[BoardConfig::KEY_CURRENT_BOARD].is_object()) {
    data[BoardConfig::KEY_CURRENT_BOARD][BoardConfig::KEY_NAME] = "";
    data[BoardConfig::KEY_CURRENT_BOARD][BoardConfig::KEY_DIRECTORY] = "";
  }

  std::ofstream b_write(BoardConfig::GLOBAL_DATA_FILE);
  if (!b_write.is_open()) {
    throw std::invalid_argument(BoardConfig::ERR_FILE_NOT_FOUND);
  }
  b_write << data;
  b_write.close();
}

void Board::Destroy() {
  std::string board_file =
      BoardConfig::BOARDS_DIRECTORY + this->entityName + ".json";
  if (CheckFileExistence(board_file) &&
      CheckJsonBoard(BoardConfig::GLOBAL_DATA_FILE)) {
    DeleteFile(board_file);
    DeleteJsonRecord(BoardConfig::GLOBAL_DATA_FILE);
  } else {
    std::cerr << BoardConfig::ERR_BOARD_DELETION;
  }
}

bool Board::CheckJsonBoard(std::string target_file) {
  std::ifstream b_save(target_file);
  if (!b_save.is_open()) {
    throw std::invalid_argument(BoardConfig::ERR_FILE_NOT_FOUND);
  }

  json data;
  b_save >> data;
  b_save.close();

  if (data.contains(this->entityName) && data[this->entityName].is_object()) {
    return true;
  } else {
    std::cerr << BoardConfig::ERR_BOARD_NOT_EXIST << "\n";
    return false;
  }
}

bool Board::CheckFileExistence(std::string target_file) {
  std::ifstream b_read(target_file);

  if (b_read.is_open()) {
    b_read.close();
    return true;
  } else {
    std::cerr << BoardConfig::ERR_FILE_NOT_FOUND << "\n";
    return false;
  }
}

bool Board::DeleteFile(std::string targetFile) {
  const char *boardObject = targetFile.c_str();
  if (std::remove(boardObject) == 0) {
    return true;
  } else {
    std::cout << "File could not be found for deletion";
    return false;
  }
}

bool Board::DeleteJsonRecord(std::string targetFile) {
  json global_file = ReadFromJson(targetFile);
  global_file.erase(this->entityName);

  if (global_file[BoardConfig::KEY_CURRENT_BOARD][BoardConfig::KEY_NAME] ==
      this->entityName) {
    global_file[BoardConfig::KEY_CURRENT_BOARD][BoardConfig::KEY_NAME] = "";
  }
  WriteBoard(targetFile, global_file);

  return true;
}

void Board::WriteBoard(std::string targetFile, json jsonInformation) {
  std::ofstream b_write(targetFile);
  if (!b_write.is_open()) {
    throw std::invalid_argument(BoardConfig::ERR_FILE_CREATE);
  }
  b_write << jsonInformation;
  b_write.close();
}

json Board::ReadFromJson(std::string targetFile) {
  std::ifstream b_save(targetFile);

  if (!b_save.is_open()) {
    throw std::invalid_argument(BoardConfig::ERR_FILE_CREATE);
  }

  json retrieveBoard;
  b_save >> retrieveBoard;

  b_save.close();

  return retrieveBoard;
}

void Board::Update() {}
