#define BOOST_TEST_MODULE BoostLog
#include <boost/test/included/unit_test.hpp>
#include <boost/test/output_test_stream.hpp>

#include <boost/log/logger.hpp>
#include <boost/log/severity.hpp>
#include <boost/log/text_printer.hpp>

template < typename LoggerType >
static void populate_logger( LoggerType & logger )
{
    boost::log::message< LoggerType >( logger )
        .severity( boost::log::Debug )
        << "debug";

    boost::log::message< LoggerType >( logger )
        .severity( boost::log::Information )
        << "information";

    boost::log::message< LoggerType >( logger )
        .severity( boost::log::Notice )
        << "notice";

    boost::log::message< LoggerType >( logger )
        .severity( boost::log::Warning )
        << "warning";

    boost::log::message< LoggerType >( logger )
        .severity( boost::log::Error )
        << "error";

    boost::log::message< LoggerType >( logger )
        .severity( boost::log::Fatal )
        << "fatal";
}

BOOST_AUTO_TEST_CASE( logger )
{
    boost::test_tools::output_test_stream output_test_stream;

    boost::log::text_printer printer( output_test_stream );
    boost::log::logger< > logger( printer );

    logger.filter( ).severity( boost::log::Fatal );
    populate_logger( logger );
    BOOST_CHECK( output_test_stream.is_equal( "fatal\n" ) );

    logger.filter( ).severity( boost::log::Information | boost::log::Warning );
    populate_logger( logger );
    BOOST_CHECK( output_test_stream.is_equal( "information\nwarning\n" ) );

    logger.filter( ).severity( boost::log::Production );
    populate_logger( logger );
    BOOST_CHECK( output_test_stream.is_equal( "information\nnotice\nwarning\nerror\nfatal\n" ) );
}
