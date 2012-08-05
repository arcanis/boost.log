//  Boost general library text_printer.hpp header file ---------------------------//
//  "THE BEER/PIZZA-WARE LICENSE" (Revision 42):
//  <nison.mael@gmail.com> wrote these files. As long as you retain this notice you
//  can do whatever you want with this stuff. If we meet some day, and you think
//  this stuff is worth it, you can buy me a beer or a pizza in return Maël Nison
//  See http://www.boost.org/ for latest version.

#ifndef BOOST_LOG_TEXT_PRINTER_HPP
#define BOOST_LOG_TEXT_PRINTER_HPP

namespace boost {

    namespace log {

        class text_printer {

        public:

            text_printer ( std::ostream & ostream )
            : m_ostream  ( ostream )
            {
            }

        public:

            template < typename Message >
            text_printer & begin( Message const & )
            {
                return * this;
            }

            template < typename Type >
            text_printer & operator<<( Type const & data )
            {
                m_ostream << data;

                return * this;
            }

            text_printer & end( void )
            {
                m_ostream << std::endl;

                return * this;
            }

        private:

            std::ostream & m_ostream;

        };

    }

}

#endif // BOOST_LOG_TEXT_PRINTER_HPP
