//  Boost general library log.hpp header file ---------------------------//
//  "THE BEER/PIZZA-WARE LICENSE" (Revision 42):
//  <nison.mael@gmail.com> wrote these files. As long as you retain this notice you
//  can do whatever you want with this stuff. If we meet some day, and you think
//  this stuff is worth it, you can buy me a beer or a pizza in return Maël Nison
//  See http://www.boost.org/ for latest version.

#ifndef BOOST_LOG_LOGGER_HPP
#define BOOST_LOG_LOGGER_HPP

#include "default_descriptor.hpp"
#include "filter.hpp"
#include "message.hpp"
#include "text_printer.hpp"

namespace boost {

    namespace log {

        template < class Printer = boost::log::text_printer, template < class Derived > class Descriptor = boost::log::default_descriptor >
        class logger {

        public:

            typedef boost::log::logger< Printer, Descriptor > self;

            typedef boost::log::message< self > message;

        public:

            template < class Derived >
            struct descriptor {
                typedef Descriptor< Derived > type;
            };

        public:

            logger      ( Printer & printer )
            : m_printer ( printer )
            , m_filter  (         )
            {
            }

        public:

            Printer & printer( void ) const
            {
                return m_printer;
            }

        public:

            boost::log::filter< self > & filter( void )
            {
                return m_filter;
            }

            boost::log::filter< self > const & filter( void ) const
            {
                return m_filter;
            }

        private:

            Printer &  m_printer;

            boost::log::filter< self > m_filter;

        };

    }

}

#endif  // BOOST_LOG_LOGGER_HPP
