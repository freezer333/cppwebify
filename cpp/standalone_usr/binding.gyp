{
  "targets": [
    {
      "target_name": "standalone_usr",
      "type": "executable",
      "sources": [ "../prime_sieve.h", "../prime_sieve.c", "main.cpp"],
      "cflags": ["-Wall", "-std=c++11"],
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