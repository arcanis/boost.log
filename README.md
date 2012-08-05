# Boost.Log (incoming) proposal

I'm currently working on a logging system for the Boost libraries.

It is purely informal : the proposal has not been made, I want to work a little more on the library before applying.

## Example

```c++
#include <iostream>

#include <boost/log/logger.hpp>
#include <boost/log/severity.hpp>
#include <boost/log/text_printer.hpp>

int main( void ) {

    // Creating the printer & logger instance
    boost::log::text_printer printer( std::cerr );
    boost::log::logger< > logger( printer );

    // It will help us in further
    typedef boost::log::logger< >::message message;

    // The logger will output every message except Debug
    logger.filter( ).severity( boost::log::Production );

    message( logger ).severity( boost::log::Debug )
        << "This is a debug message, it will not be printed in Production mode";

    message( logger ).severity( boost::log::Information )
        << "Other message types will be printed.";

    return 0;
}
```

## Installation

On Archlinux :

    $> git clone git@github.com:arcanis/side.boost.log boost.log
    $> cd boost.log
    $> makepkg
    $> sudo pacman -U boost.log-*.pkg.tar.xz

## Why ?

I'm not satisfied by current C++ logging solutions, and most of my friends weren't neither.

So here comes this Boost.Log proposal. The library is :

- Beautiful : The API has been carefully designed, and loggers are very similar to standard streams
- Simple : It does not take more than a few headers to include a logger inside an application
- Powerful : The users can create their own log message classes, with their own attributes
- Light : Almost no compilation overhead, and a very little runtime footprint

## Features

### Printer

- boost::log::text_printer

### Attributes

- boost::log::severity_attribute
