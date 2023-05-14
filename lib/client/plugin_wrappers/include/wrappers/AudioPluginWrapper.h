#ifndef AUDIOPLUGINWRAPPER_H
#define AUDIOPLUGINWRAPPER_H

#include <memory>
#include <string>
#include <vector>

#include "interfaces/IAudioPluginWrapper.h"
#include "wrappers/BasicPluginWrapper.h"

class AudioPluginWrapper : public BasicPluginWrapper,
                           virtual public IAudioPluginWrapper {
 public:
    AudioPluginWrapper(std::shared_ptr<IRequestable> connection);
    std::pair<std::vector<std::pair<std::string, std::string>>, std::string>
    get(const std::string &word, size_t batch_size) override;
};

#endif  // AUDIOPLUGINWRAPPER_H
