#pragma once

#include <memory>

#include "IOStream.h"
#include "MaaFramework/MaaPort.h"

MAA_NS_BEGIN

class MAA_UTILS_API ChildPipeIOStream : public IOStream
{
public:
    ChildPipeIOStream(const std::filesystem::path& exec, const std::vector<std::string>& args);

    virtual ~ChildPipeIOStream();

public:
    virtual bool write(std::string_view data) override;

    virtual bool release() override;
    virtual bool is_open() const override;

protected:
    virtual std::string read_once(size_t max_count) override;

private:
    boost::process::ipstream pin_;
    boost::process::opstream pout_;
    boost::process::child child_;

    std::unique_ptr<char[]> buffer_ = nullptr;
};

MAA_NS_END