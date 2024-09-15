#pragma once

namespace provider
{
    enum class database_type
    {
        mysql,
        sqlite,
        mongodb
    };
    
    class provider
    {
        static database_type database_type_;
        
    public:
        provider(database_type database_type);

        static auto get_provider();
    };
}
