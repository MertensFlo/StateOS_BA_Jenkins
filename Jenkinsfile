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
                    buildStage.build(true, true, true, true, true,true, true, "MertensFlo", "StateOS_BA_Jenkins", "11.3.rel1")  //(boolean git, boolean wget, boolean xz-utils, boolean arm, boolean build-essential, boolean apt-utils,String workingOrg, String workingRepo, String arm_version)
                }
            }
        }
        stage('example_test') {
            steps {
                script{
                    def testStage = new StageTest()
                    testStage.test(true, false, false, true, "11.3.rel1", "StateOS_BA_Jenkins") //(boolean example_test, boolean static_code, boolean unit_test, boolean arm, String arm_version, String workingRepo)
                }
            }
        }
        stage('static_code_test') {
            steps {
                script{
                    def testStage = new StageTest()
                    testStage.test(false, true, false, true, "11.3.rel1", "StateOS_BA_Jenkins") //(boolean example_test, boolean static_code, boolean unit_test, boolean arm, String arm_version, String workingRepo)
                }
            }
        }
        stage('unit_test') {
            steps {
                script{
                    def testStage = new StageTest()
                    testStage.test(false, false, true, true, "11.3.rel1", "StateOS_BA_Jenkins") //(boolean example_test, boolean static_code, boolean unit_test, boolean arm, String arm_version, String workingRepo)
                } 
            }
        }
    }
}
