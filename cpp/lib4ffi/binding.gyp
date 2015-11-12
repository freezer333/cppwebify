{
  "targets": [
    {
      "target_name": "libprime",
      "type": "executable",
      "sources": [ "../prime4lib/prime_sieve.h", "../prime4lib/prime_sieve.c", "../prime4lib/arbiter.cpp", "primeapi.cpp"],
      "cflags": ["-Wall", "-std=c++11"],
      "include_dirs" : ['../prime4lib'],
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