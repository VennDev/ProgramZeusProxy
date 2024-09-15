#include "provider.h"

namespace provider
{
    database_type provider::database_type_;
    
    provider::provider(database_type database_type)
    {
        database_type_ = database_type;
    }

    auto provider::get_provider()
    {
        if (database_type_ == database_type::mysql)
        {
            return "mysql";
        }
        else if (database_type_ == database_type::sqlite)
        {
            return "sqlite";
        }
        else if (database_type_ == database_type::mongodb)
        {
            return "mongodb";
        }

        return "unknown";
    }
    
}
