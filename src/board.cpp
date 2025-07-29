#include "../include/mtask/board.h"
#include "../include/mtask/board_config.h"

Board::Board(std::string name) {
  this->entityName = name;
  CheckDirectorySetup();
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

void Board::SelectBoard(std::string boardName) {
  std::ifstream b_read(BoardConfig::GLOBAL_DATA_FILE);
  if (!b_read.is_open()) {
    throw std::invalid_argument(BoardConfig::ERR_FILE_NOT_FOUND);
  }

  json data;
  b_read >> data;
  b_read.close();

  if (data.contains(boardName) && data[boardName].is_object()) {
    data[BoardConfig::KEY_CURRENT_BOARD][BoardConfig::KEY_NAME] = boardName;
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
  std::ifstream b_read(BoardConfig::GLOBAL_DATA_FILE);
  if (!b_read.is_open()) {
    throw std::invalid_argument(BoardConfig::ERR_FILE_NOT_FOUND);
  }

  json data;
  b_read >> data;

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

void Board::Update() {}

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

// Helper Functions

// Checks if file/board is documented in the JSON file.
bool Board::CheckJsonBoard(std::string targetFile) {
  std::ifstream b_read(targetFile);
  if (!b_read.is_open()) {
    throw std::invalid_argument(BoardConfig::ERR_FILE_NOT_FOUND);
  }

  json data;
  b_read >> data;
  b_read.close();

  if (data.contains(this->entityName) && data[this->entityName].is_object()) {
    return true;
  } else {
    std::cerr << BoardConfig::ERR_BOARD_NOT_EXIST << "\n";
    return false;
  }
}

void Board::CheckDirectorySetup() {
  if (!std::filesystem::exists(BoardConfig::BOARDS_DIRECTORY)) {
    std::cout
        << "'boards' directory not found, directory has been created...\n";
    std::filesystem::create_directory("boards");
  }

  if (!CheckFileExistence(BoardConfig::GLOBAL_DATA_FILE)) {
    std::ofstream b_write(BoardConfig::GLOBAL_DATA_FILE);
    json default_data;
    default_data[BoardConfig::KEY_CURRENT_BOARD] = {
        {BoardConfig::KEY_DIRECTORY, ""}, {{BoardConfig::KEY_NAME, ""}}};
    WriteBoard(BoardConfig::GLOBAL_DATA_FILE, default_data);
    std::cout << "Global data file not found, file has been created...\n";
  }
}

bool Board::CheckFileExistence(std::string targetFile) {
  std::ifstream b_read(targetFile);

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
  std::ifstream b_read(targetFile);

  if (!b_read.is_open()) {
    throw std::invalid_argument(BoardConfig::ERR_FILE_CREATE);
  }

  json retrieveBoard;
  b_read >> retrieveBoard;

  b_read.close();

  return retrieveBoard;
}
