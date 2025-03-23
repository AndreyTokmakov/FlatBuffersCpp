/**============================================================================
Name        : main.cpp
Created on  : 04.06.2024
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description : FlatBuffers experiments
============================================================================**/

#include <iostream>
#include <print>


#include <vector>
#include <string_view>


#include "all_headers.h"

namespace
{
    using String = flatbuffers::String;
    using Message = messaging::Message;
}

namespace SimpleTests
{
    void createMessage()
    {
        flatbuffers::FlatBufferBuilder builder(1024);
        const flatbuffers::Offset<String> text = builder.CreateString("Some_Text");

        const flatbuffers::Offset<Message> message = messaging::CreateMessage(
                builder,text, 12345, messaging::Status::Success);

        builder.Finish(message);

        /** Pointer to serialized data and data length: **/
        const uint8_t* bytes = builder.GetBufferPointer();
        const int size = builder.GetSize();


        const Message* msg = messaging::GetMessage(bytes);

        std::println("Message(id: {}, text: {}, status: {})",
                     msg->id(), msg->text()->str(), EnumNameStatus(msg->status()));

    }
}


int main([[maybe_unused]] int argc,
         [[maybe_unused]] char** argv)
{
    const std::vector<std::string_view> args(argv + 1, argv + argc);

    SimpleTests::createMessage();

    return EXIT_SUCCESS;
}

