#include "workspace.h"
#include <cstdio>
#include <filesystem>
class Board : public IWorkspace {
public:
  Board(std::string name);
  void HandleCommand(std::string command, std::string name) override;

private:
  // Core Functions
  void Create(std::string boardName) override;
  void Destroy() override;
  void Update() override;
  void SelectBoard(std::string boardName);
  void DeselectBoard(std::string boardName);
  void CheckDirectorySetup();

  // Helper Functions
  bool DeleteFile(std::string targetFile);
  bool DeleteJsonRecord(std::string targetFile);
  bool CheckFileExistence(std::string targetFile);
  bool CheckJsonBoard(std::string targetFile);
  void WriteBoard(std::string targetFile, json jsonInformation);
  json ReadFromJson(std::string targetFile);
};
