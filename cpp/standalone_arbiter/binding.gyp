{
  "targets": [
    {
      "target_name": "standalone_arbiter",
      "type": "executable",
      "sources": [ "prime_sieve.h", "prime_sieve.c", "arbiter.cpp", "main.cpp"],
      "cflags": ["-Wall", "-std=c++11", "-stdlib=libc++"],
      "conditions": [ 
        [ 'OS=="mac"', { 
            "xcode_settings": { 
                'OTHER_CPLUSPLUSFLAGS' : ['-std=c++11','-stdlib=libc++'], 
                'OTHER_LDFLAGS': ['-stdlib=libc++'], 
                'MACOSX_DEPLOYMENT_TARGET': '10.7' } 
            }
        ] 
      ] 
    }
  ]
}