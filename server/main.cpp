#include "DefinitionsProviderWrapper.hpp"
#include "FormatProcessorWrapper.hpp"
#include "PluginsProvider.hpp"
#include "Server.hpp"
#include <boost/asio.hpp>
#include <cstdint>
#include <iostream>
#include <memory>

auto main(int argc, char *argv[]) -> int {
    Py_Initialize();
    auto plugins_dirs = PluginTypesLocationsConfig{
        .definitions_providers_dir =
            "/home/blackdeer/projects/cpp/technopark/plugins/definitions/",
        .sentences_providers_dir =
            "/home/blackdeer/projects/cpp/technopark/plugins/sentences/",
        .images_providers_dir =
            "/home/blackdeer/projects/cpp/technopark/plugins/images/",
        .audios_providers_dir =
            "/home/blackdeer/projects/cpp/technopark/plugins/audios/",
        .format_processors_dir = "/home/blackdeer/projects/cpp/technopark/"
                                 "plugins/format_processors/"};

    boost::asio::io_context io_context;
    auto                    plugins_provider =
        std::make_shared<PluginsProvider>(std::move(plugins_dirs));
    constexpr uint16_t port = 8888;
    auto server = PluginServer(std::move(plugins_provider), io_context, port);
    io_context.run();
}