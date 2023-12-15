#pragma once
#include <fstream>
#include <vector>
#include <mutex>

#include "../defines.hpp"
#include "../helpers/MiscFunctions.hpp"

struct SHyprIPCEvent {
    std::string event;
    std::string data;
};

class CEventManager {
  public:
    CEventManager();

    void        postEvent(const SHyprIPCEvent event);

    void        startThread();

    std::thread m_tThread;

  private:
    std::vector<std::pair<int, wl_event_source*>> m_vAcceptedSocketFDs;
};

inline std::unique_ptr<CEventManager> g_pEventManager;
