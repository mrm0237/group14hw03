// We have to make a file for Jenkins to understand
pipeline {
  agent any

  stages {
    stage('Checkout') {
      steps {
        checkout scm
      }
    }
    stage('Build and Test') {
      steps {
        sh 'chmod +x run_tests.sh'
        sh './run_tests.sh'
      }
    }
  }

  post {
    always {
      archiveArtifacts artifacts: 'actual_output.txt', allowEmptyArchive: true
    }
  }
}
