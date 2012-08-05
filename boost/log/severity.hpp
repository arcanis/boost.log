#ifndef BOOST_LOG_SEVERITY_HPP
#define BOOST_LOG_SEVERITY_HPP

namespace boost
{

    namespace log
    {

        enum default_severity_levels {

            Debug       = ( 1 << 0 ),
            Information = ( 1 << 1 ),
            Notice      = ( 1 << 2 ),
            Warning     = ( 1 << 3 ),
            Error       = ( 1 << 4 ),
            Fatal       = ( 1 << 5 ),

            None        = 0,
            Production  = Information | Notice | Warning | Error | Fatal,
            Development = Production | Debug,

        };

        template < typename Base >
        class severity_attribute
        {

        public:

            severity_attribute ( void )
            : m_severity       ( 0 )
            {
            }

        public:

            Base & severity( int severity )
            {
                m_severity = severity;

                return static_cast< Base & >( * this );
            }

            int severity( void ) const
            {
                return m_severity;
            }

        private:

            int m_severity;

        };

    }

}

#endif
