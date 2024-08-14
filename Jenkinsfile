// Uses Declarative syntax to run commands inside a container.
@Library('StateOS_Bachelor_Thesis')_

node {
    kubernetes {
        // Rather than inline YAML, in a multibranch Pipeline you could use: yamlFile 'jenkins-pod.yaml'
        // Or, to avoid YAML:
        // containerTemplate {
        //     name 'shell'
        //     image 'ubuntu'
        //     command 'sleep'
        //     args 'infinity'
        // }
        yaml '''
            apiVersion: v1
            kind: Pod
            spec:
            containers:
            - name: shell
                image: artifactory-04.boschdevcloud.com/docker-virtual/ubuntu:latest
                command:
                - sleep
                args:
                - infinity
            imagePullSecrets:
            - name: gds-secret-dockerreg-cs27-artifactory-04
            '''
        defaultContainer 'shell'
        retries 2
    }
    new Pipeline_(this).pipeline_build(
        true,true,true,true,
        true,true,true,true,true,true,true,true,
        "MertensFlo","StateOS_BA_Jenkins",
        "https://developer.arm.com/-/media/Files/downloads/gnu/11.3.rel1/binrel/arm-gnu-toolchain-11.3.rel1-x86_64-arm-none-eabi.tar.xz",
        "arm-gnu-toolchain-11.3.rel1-x86_64-arm-none-eabi.tar.xz",
        "${{github.workspace}}/arm-gnu-toolchain-11.3.rel1-x86_64-arm-none-eabi/bin",
        "q", "cmake"
        )
    //(Boolean flag_build, Boolean flag_example_test, Boolean flag_static_test, Boolean flag_unit_test, 
    // Boolean flag_git, Boolean flag_wget, Boolean flag_xz_utils, Boolean flag_arm, Boolean flag_build_essential, Boolean flag_apt_utils, Boolean flag_ninja, Boolean flag_submodule, 
    // String workingOrg, String workingRepo, 
    // String arm_path, 
    // String arm_tar_path, 
    // String arm_dir_path, 
    // String arm_condition, String cmake_version)
}

