#pragma once
#include <fstream>
#include <vector>
#include <mutex>
#include <thread>

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

    int         m_iSocketFD = -1;

    int         onSocket2Write(int fd, uint32_t mask);
    int         onFDWrite(int fd, uint32_t mask);

  private:
    std::vector<std::pair<int, wl_event_source*>> m_vAcceptedSocketFDs;

    wl_event_source*                              m_pEventSource = nullptr;
};

inline std::unique_ptr<CEventManager> g_pEventManager;
