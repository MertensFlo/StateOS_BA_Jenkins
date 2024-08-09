// Uses Declarative syntax to run commands inside a container.
@Library('StateOS_Bachelor_Thesis')_

pipeline {
    agent {
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
    }
    stages {
        stage('build') {
            steps{
                script{
                    def buildStage = new StageBuild()
                    buildStage.build()
                }
            }
        }
        stage('example_test') {
            steps {
                script{
                    def testStage = new StageTest()
                    testStage.example_test()
                    /*
                    sh '''
                        apt-get -y -qq update && apt-get -y -qq install cmake ninja-build
                        wget -q https://developer.arm.com/-/media/Files/downloads/gnu/11.3.rel1/binrel/arm-gnu-toolchain-11.3.rel1-x86_64-arm-none-eabi.tar.xz
                        echo "1"
                        tar -xf arm-gnu-toolchain-11.3.rel1-x86_64-arm-none-eabi.tar.xz
                    '''
                    env.JENKINS_PATH = "${env.WORKSPACE}/arm-gnu-toolchain-11.3.rel1-x86_64-arm-none-eabi/bin"
                    sh '''
                        arm-none-eabi-gcc -v
                        cd StateOS_BA_Jenkins
                        cmake -S. -Bbuild -GNinja
                        cmake --build build -v 
        
                        sh ./.example-test.sh
                    '''*/
                }
            }
        }
        stage('static_code_test') {
            steps {
                script{
                    def testStage = new StageTest()
                    testStage.static_test()
                /*
                script{
                    sh '''
                        apt-get -y -qq update && apt-get -y -qq install cmake ninja-build
                        wget -q https://developer.arm.com/-/media/Files/downloads/gnu/11.3.rel1/binrel/arm-gnu-toolchain-11.3.rel1-x86_64-arm-none-eabi.tar.xz
                        echo "1"
                        tar -xf arm-gnu-toolchain-11.3.rel1-x86_64-arm-none-eabi.tar.xz
                    '''
                    env.JENKINS_PATH = "${env.WORKSPACE}/arm-gnu-toolchain-11.3.rel1-x86_64-arm-none-eabi/bin"
                    sh '''
                        arm-none-eabi-gcc -v
                        cd StateOS_BA_Jenkins
                        cmake -S. -Bbuild -GNinja
                        cmake --build build -v 
        
                        sh ./.stdc++-test.sh
                    '''*/
                    
                }
            }
        }
        stage('unit_test') {
            steps {
                script{
                    def testStage = new StageTest()
                    testStage.unit_test()
                /*
                script{
                    sh '''
                        apt-get -y -qq update && apt-get -y -qq install cmake ninja-build
                        wget -q https://developer.arm.com/-/media/Files/downloads/gnu/11.3.rel1/binrel/arm-gnu-toolchain-11.3.rel1-x86_64-arm-none-eabi.tar.xz
                        echo "1"
                        tar -xf arm-gnu-toolchain-11.3.rel1-x86_64-arm-none-eabi.tar.xz
                    '''
                    env.JENKINS_PATH = "${env.WORKSPACE}/arm-gnu-toolchain-11.3.rel1-x86_64-arm-none-eabi/bin"
                    sh '''
                        arm-none-eabi-gcc -v
                        cd StateOS_BA_Jenkins
                        cmake -S. -Bbuild -GNinja
                        cmake --build build -v 
        
                        sh 'make all -f .unit-test.make
                    '''*/
                }
            }
        }
    }
}
