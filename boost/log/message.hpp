#ifndef BOOST_LOG_MESSAGE_HPP
#define BOOST_LOG_MESSAGE_HPP

#include <iostream>

namespace boost
{

    namespace log
    {

        template < class Logger >
        class message : public Logger::template descriptor< message< Logger > >::type
        {

        private:

            enum status_type {
                Pending,
                Printing,
                Dropping
            };

        public:

            message    ( Logger const & logger )
            : m_logger ( logger  )
            , m_status ( Pending )
            {
            }

        public:

            ~message( void )
            {
                if ( m_status == Printing ) {
                    m_logger.printer( ).end( );
                }
            }

        public:

            template < typename DataType >
            message< Logger > & operator<<( DataType const & data )
            {
                if ( m_status == Pending ) {
                    if ( m_logger.filter( ).validate( * this ) ) {
                        m_status = Printing;
                        m_logger.printer( ).begin( * this );
                    } else {
                        m_status = Dropping;
                    }
                }

                if ( m_status == Printing )
                    m_logger.printer( ) << data;

                return * this;
            }

        private:

            Logger const & m_logger;

            status_type    m_status;

        };

    }

}

#endif
